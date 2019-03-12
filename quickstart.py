from __future__ import print_function
import pickle
import os.path
import base64
import email
from apiclient import errors
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText
import httplib2
import os
import time
import serial
from apiclient import discovery, errors




# If modifying these scopes, delete the file token.pickle.
SCOPES = ['https://mail.google.com/']

def DeleteMessage(service, user_id, msg_id):
  """Delete a Message.

  Args:
    service: Authorized Gmail API service instance.
    user_id: User's email address. The special value "me"
    can be used to indicate the authenticated user.
    msg_id: ID of Message to delete.
  """
  try:
    service.users().messages().delete(userId=user_id, id=msg_id).execute()
    print ('Message with id: {} deleted successfully.' .format( msg_id))
  except errors.HttpError, error:
    print ('An error occurred: {}' .format( error))

def create_message(sender, to, subject, message_text):
  """Create a message for an email.

  Args:
    sender: Email address of the sender.
    to: Email address of the receiver.
    subject: The subject of the email message.
    message_text: The text of the email message.

  Returns:
    An object containing a base64url encoded email object.
  """
  message = MIMEText(message_text)
  message['to'] = to
  message['from'] = sender
  message['subject'] = subject
  return {'raw': base64.urlsafe_b64encode(message.as_string())}

def SendMessage(service, user_id, message): # Send an email message.
    try:
        message = (service.users().messages().send(userId=user_id, body=message)
           .execute())
        print ('Message Id: {}' .format( message['id']))
        return message
    except errors.HttpError as error:
        print ('An error occurred: {}' .format( error))

def ModifyMessage(service, user_id, msg_id, msg_labels):
  """Modify the Labels on the given Message.

  Args:
    service: Authorized Gmail API service instance.
    user_id: User's email address. The special value "me"
    can be used to indicate the authenticated user.
    msg_id: The id of the message required.
    msg_labels: The change in labels.

  Returns:
    Modified message, containing updated labelIds, id and threadId.
  """
  try:
    message = service.users().messages().modify(userId=user_id, id=msg_id, body=msg_labels).execute()

    label_ids = message['labelIds']

    print ('Message ID: {} - With Label IDs {}' .format(msg_id, label_ids))

  except errors.HttpError, error:
    print('An error occurred: {}' .format(error))





# modifyMessage('<message-id>', ['UNREAD'], callback);
def stringFixer(tofix):
    startIndex = tofix.find("message:")
    endIndex = tofix.find("Submitted ")
    cropBody = tofix[startIndex+8:endIndex]
    nospace = cropBody.rstrip()
    print(nospace)
    f = open("words.txt", "a")
    f.write(nospace)
    nospace = nospace+">"
    return nospace


def sendData(messageToSend):

    arduino = serial.Serial('/dev/cu.usbmodem1421', 115200, timeout=1)
    time.sleep(3) #give the connection a second to settle
    arduino.write(messageToSend)
    time.sleep(40)



def GetMessageBody(service, user_id, msg_id):
    try:
        message = service.users().messages().get(userId=user_id, id=msg_id, format='raw').execute()
        msg_str = base64.urlsafe_b64decode(message['raw'].encode('ASCII'))
        mime_msg = email.message_from_string(msg_str)
        messageMainType = mime_msg.get_content_maintype()
        if messageMainType == 'multipart':
            for part in mime_msg.get_payload():
                if part.get_content_maintype() == 'text':
                    return part.get_payload()
                return ""
        elif messageMainType == 'text':
            return mime_msg.get_payload()

    except: pass

def main():
    """Shows basic usage of the Gmail API.
    Lists the user's Gmail labels.
    """

    running = True
    try:
        while(running):
            creds = None
            # The file token.pickle stores the user's access and refresh tokens, and is
            # created automatically when the authorization flow completes for the first
            # time.
            if os.path.exists('token.pickle'):
                with open('token.pickle', 'rb') as token:
                    creds = pickle.load(token)
            # If there are no (valid) credentials available, let the user log in.
            if not creds or not creds.valid:
                if creds and creds.expired and creds.refresh_token:
                    creds.refresh(Request())
                else:
                    flow = InstalledAppFlow.from_client_secrets_file(
                        'credentials.json', SCOPES)
                    creds = flow.run_local_server()
                # Save the credentials for the next run
                with open('token.pickle', 'wb') as token:
                    pickle.dump(creds, token)

            service = build('gmail', 'v1', credentials=creds)

            # Call the Gmail API

            response = service.users().messages().list(userId='me', labelIds="Label_2713646231012778643",  ).execute()
            messages = response.get('messages', [])


            if not messages:
                print('No messages found.')
            else:
                print('Messages:')
                for message in messages:
                     fullBody = (GetMessageBody(service,'me',message['id']))
                     goodString = stringFixer(fullBody)
                     test = create_message('footballshane@gmail.com','footballshane@gmail.com','In case ya missed it',fullBody)
                     SendMessage(service,'footballshane@gmail.com',test)
                     DeleteMessage(service,'me',message['id'])
                     sendData(goodString)

            time.sleep(5)
    except KeyboardInterrupt:
        pass












if __name__ == '__main__':
    main()





#stylesheet
