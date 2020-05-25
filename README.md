# strangerthings
Phrases entered into a form on my website(shanefolden.com/lights) light up on my dorm wall using addressable LEDs.

This is based off of the scene in stranger things where Will lights up christmas lights in order to send a message to his mom.


![](outputgif.gif)


## Hardware
- Arduino Uno 
- ALITOVE WS2811 Individually addressable LEDs 
  - standard LEDs wouldnt work since we need to light up specific LEDs for each letter
- Basic USB webcam 
  - This isnt required, I just got it so I could livestream the lights on my website so people could see their entries go through
 - Really old laptop
    - I'm just using this temporarily to run the python script and OBS, the streaming software. 
  
## How it works

A user submits the form on shanefolden.com/lights with their message. This is handled by formspree.io, a free form handling service. Since I pnly have the free version, I don't have access to their API directly and can't download the data. However, I am able to have the message emailed to me. 

I then use Python implement the Gmail API  to automatically flag any emails from formspree that come in, determine they are from the lights form, and then scrape the email for the message. I then open a connection with the arduino and send the message to it through the serial port. I then save all the useful data from the email locally and then delete the email so it's not double counted.

The arduino runs a really simple program that reads serial input until the message is completed and then lights up the correct LED for each character in the message. The python script sleeps during this time so messages arent interrupted.

I then set up a usb webcam on my closet door, run it through OBS on the laptop and stream it to twitch. The twitch stream is embedded on my site. 

## Current Problems
- On rare occasions, formspree decides to take 2-5 minutes to send an email which results in a huge delay
  - This will be fixed once I write a PHP script to get form data which will cut formspree out of the equation entirely
  
- The school wifi here is really bad so sometimes the laptop disconnects without me noticing which breaks everything
  - This should be fixed once I move everything over to my raspberry pi which has a wired connection
  
- I add the character '>' at the end of the string I send the arduino that way it knows when the message is over. However, I don't sanitize inputs for that character so if the message contains '>' it could mess with the output to the wall. 
    - This could be fixed super easily whenever I get around to it, I'm just kind of lazy and it hasn't been a problem yet
 



