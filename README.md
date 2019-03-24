# Spy cam detector: Mobile Minder

## Inspiration
South Korea is experiencing an epidemic of spy cams, positioned in public restrooms, hotel rooms, and other intimate locations to secretly record people's activities without their consent. Also known as “molka”, this problem is serious and growing: the police received over 6,400 illegal recording reports in 2017, an increase of 4,000 from 2012. It has also been the subject of public protests attended by tens of thousands proclaiming “my life is not your porn.” While the South Korean government has recognized the severity and urgency of this problem, their progress has been inhibited by the variable and clandestine tactics utilized by perpetrators. Spy cams can be hidden in everything from hair dryer stands to car keys to outlets, and the cybersecurity precautions taken by perpetrators complicates their detection. In the absence of a centralized and robust tool for detecting spy cams, affected citizens are left to rely on Android and iOS apps of questionable reliability that have received mixed reviews. In particular, these apps typically take advantage of only one mode of detection, usually light, thus lacking potential robustness that could be obtained by including sound, EMF, or RF interference.

## What it does
We have built an IoT device to locate spy cams using a variety of distinct methods. Statistical analyses run on our sound detector can detect audio anomalies suggesting the click of a motion-activated camera. For added robustness, we pair a photoresistor with an LED to sense the telltale glint of a camera lens. We are looking into incorporating EMF and RF detection mechanisms as well, which are underutilized in pre-existing detectors currently on the markets but represent a promising additional source of corroboration. The outputs of these sensors connect to a real-time graph through the Arduino Serial Plotter which can be monitored and used to trigger an alarm.

## How we built it
Our device is based on an Arduino Uno. We also implemented sound and light Grove Seeed sensors. Our code was written in C++ for Arduino supported by statistical packages.

## Challenges we ran into
Initially, we struggled with connecting the Arduino to the sensors and receiving their output, as this involved adaptors and commands we were not familiar with. We also had several failed attempts at making EMF detectors, and had to make an executive decision to prioritize the simpler metrics.

## Accomplishments we're proud of
Despite having no significant prior experience with hardware and barely any C++ knowledge, we were able to build a working device that combines input from multiple sensors and which could actually be used to help individuals find hidden cameras. In doing so, we were able to at least begin to address such a huge issue as the spycam epidemic in Korea, providing a pathway toward future, more advanced solutions. 

## What we learned
Throughout this hackathon, we tinkered with an Arduino Uno, developing a good sense of how to work with electronics and hardware. For this project, we also learned how to program in C++, and learned how to use both a sound sensor and a light sensor to detect any sounds or light coming from spycams. For version control and in order to optimize the collaboration process, we also learned how to use Git and Github.

## What's next for Mobile Minder
We plan to prioritize our future efforts on finalizing our Electromagnetic Field and Radio Frequency sensors, which are relatively novel in this application but hold much promise. We also look forward to fine-tuning our statistical algorithms to improve the specificity and sensitivity of our models.
