import speech_recognition as sr
import requests  # Import the requests library
import time


auth = ""                                  # enter your Blynk authtoken in the string
# Function to trigger the webhook
def forward():
    webhook_url = "https://sgp1.blynk.cloud/external/api/update?token="+auth+"&v0=1"
    
    try:
        response = requests.get(webhook_url)
        
        if response.status_code == 200:
            print("Webhook triggered successfully.")
        else:
            print(f"Failed to trigger webhook. Status code: {response.status_code}")
    
    except requests.exceptions.RequestException as e:
        print(f"Error triggering webhook: {e}")
        
def backward():
    webhook_url = "https://sgp1.blynk.cloud/external/api/update?token="+auth+"&v1=1"
    
    try:
        response = requests.get(webhook_url)
        
        if response.status_code == 200:
            print("Webhook triggered successfully.")
        else:
            print(f"Failed to trigger webhook. Status code: {response.status_code}")
    
    except requests.exceptions.RequestException as e:
        print(f"Error triggering webhook: {e}")        

def right():
    webhook_url = "https://sgp1.blynk.cloud/external/api/update?token="+auth+"&v2=1"
    
    try:
        response = requests.get(webhook_url)
        
        if response.status_code == 200:
            print("Webhook triggered successfully.")
        else:
            print(f"Failed to trigger webhook. Status code: {response.status_code}")
    
    except requests.exceptions.RequestException as e:
        print(f"Error triggering webhook: {e}")


def left():
    webhook_url = "https://sgp1.blynk.cloud/external/api/update?token="+auth+"&v3=1"
    
    try:
        response = requests.get(webhook_url)
        
        if response.status_code == 200:
            print("Webhook triggered successfully.")
        else:
            print(f"Failed to trigger webhook. Status code: {response.status_code}")
    
    except requests.exceptions.RequestException as e:
        print(f"Error triggering webhook: {e}")
        
def spin():
    webhook_url = "https://sgp1.blynk.cloud/external/api/update?token="+auth+"&v6=1"
    
    try:
        response = requests.get(webhook_url)
        
        if response.status_code == 200:
            print("Webhook triggered successfully.")
        else:
            print(f"Failed to trigger webhook. Status code: {response.status_code}")
    
    except requests.exceptions.RequestException as e:
        print(f"Error triggering webhook: {e}")
        
def stop():
    webhook_url = "https://sgp1.blynk.cloud/external/api/update?token="+auth+"&v4=1"
    
    try:
        response = requests.get(webhook_url)
        
        if response.status_code == 200:
            print("Webhook triggered successfully.")
        else:
            print(f"Failed to trigger webhook. Status code: {response.status_code}")
    
    except requests.exceptions.RequestException as e:
        print(f"Error triggering webhook: {e}")

def voiceCommands(string):
    if "forward" == string.lower():  # Case insensitive
        print("Going forwards...")
        forward()
    elif "backward" == string.lower():
        print("Going backwards...")
        backward()
    elif "right" == string.lower():
        print("Going right...")
        right()
    elif "left" == string.lower():
        print("Going left...")
        left()
    elif "spin" == string.lower():
        print("weeeee")
        spin()
    elif "quit" == string.lower():        # Exits from the infinite loop via keyboard interrupt
        print("ending voice commands...")
        raise KeyboardInterrupt()
    elif "stop" == string.lower():
        print("ending voice commands...")
        stop()
# Initialize recognizer
recognizer = sr.Recognizer()

# Use the microphone as the audio source
with sr.Microphone() as source:
    print("Adjusting for ambient noise...")
    recognizer.adjust_for_ambient_noise(source)  # Adjusting for ambient noise
    print("Listening for speech...")

    while True:  # Keep listening indefinitely
        audio = recognizer.listen(source)  # Capture the speech

        try:
            print("Recognizing...")
            text = recognizer.recognize_google(audio)  # Use Google's speech recognition
            print("You said: " + text)  # Output the recognized text

            if (len(text.split(sep=" ")) < 1):
                voiceCommands(text)
            else:                                    # a bunch of commands said in succession like, "forward backward spin spin stop left"
                for words in text.split(sep=" "):
                    voiceCommands(words.lower())
                    time.sleep(5)
        except sr.UnknownValueError:
            print("Sorry, I couldn't understand the speech.")
        except sr.RequestError:
            print("Sorry, there was an error with the speech service.")
