# Autonomous Parallel Parking Car Using Arduino With Radio and Windshield Wipers


In this project we had three objectives, to achieve assistive parallel parking,
automatic windshield wipers(and fuel detectors), and finally, a touchpad-accessible radio.
1
Specifications
Our components consisted of the following: 4 car motors, one plastic car, one
breadboard, a lot of AA batteries, an arduino Uno, an arduino Mega, 2 H-Bridges, one
TEA5767 radio, one TFT LCD 2.4”, 4 IR proximity sensors, one rain sensor, one servomotor,
one water sensor, and one seven-segment display. This, coupled with an abundance of
jumper cables as well as 2 USB cables and some resistors, helped us achieve the previously
mentioned objective.
These were not our only tools, as we had other libraries as well:
Inputs and Outputs
Most input pins were sensors, and these included the 4 IR sensors SENSOR1
through SENSOR4. Other sensors include capteur_D and capteur_A, which are the digital
and analog pins for the rain sensor. Finally, some sensors and other pins are supposed to
be treated as output as well, for example the sensorPin for the water sensor and the pins
in the LCD screen.
Output pins were in the majority as output pins were often used to control the
power going to certain components, such as the radioPower pin and the enable and IN pins
in the H-bridges. Other outputs were XM and YM on the touch screen which signified where
a person may have touched the screen. Finally, seven segment display sevSegPower was
also a part of the outputs.
Scheduling
2
In the end we used FreeRTOS in order to schedule our tasks so they could run together
smoothly, and by doing that we hoped that we can achieve maximum efficiency, going only
a little beneath the little tick between each task. We divided all our workload into three
tasks, one for motion, one for protection and one for entertainment. Giving priority to the
driving part, we managed to form a well organized unit for a while until some of our
components got burnt.
Our limitations became the lack of components as our components betrayed us and
started burning out at a quick rate by the nearing 3 hours. At some point we had to rewrite
the code because the laptop had been nearly fried and it stopped working for a long while.
Work division was quite simple as mentioned in the video, Mahmoud handled most
hardware, Youssef held a bit more hardware than software, Ziad handled more software
than hardware, and Morsy held an equal balance of both. I handled some of the LCD wiring
and the freeRTOS, Youssef handled the radio and the LCD, Ziad handled the car motors
and sensors, and Morsy handled the rain and fuel sensor
