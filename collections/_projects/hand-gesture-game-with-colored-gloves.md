---
layout: project
title: Hand Gesture Game with Colored Gloves
front_image: /assets/img/projects/colored-gloves/colored-gloves-banner.jpg
thumbnail: /assets/img/projects/colored-gloves/colored-gloves-thumb.jpg
accent_color: "#76a72e"
tags:
  - AI
  - Game
  - Multimedia
---

For the Multimedia Systems elective course of the Computer Science master, the main project involved splitting into groups and developing an application in some way related to multimedia systems. I worked together with Dekel Zak ([GitHub](https://github.com/dekelzeldov); [LinkedIn](https://www.linkedin.com/in/dekelzeldov/)) and Perri van den Berg ([GitHub](https://github.com/PerrivandenBerg); [LinkedIn](https://www.linkedin.com/in/perrivandenberg/)) to create a game that can be played purely with hand gestures and hand movement as input. You can view the source code by clicking the button below. Installation instructions can be found [at the bottom of this page](#installation).

{% include center-button.html icon="link" text="Project code" href="https://github.com/dirckvdende/multimedia-systems-project" %}

The application we created contains three mini-games, each showcasing a different type of interaction. I've listed them below.

## Apple Catch

Apple Catch is the simplest minigame. It involves a player holding one hand in front of the camera and moving it around. The position of the hand controls the position of a basket on the screen. The player has to catch as many apples in the basket as possible without missing one.

![Apple Catch game screenshot](/assets/img/projects/colored-gloves/apple-catch.png)

## Pick 'n Slot

The Pick 'n Slot game showcases the detection of gestures and detection of hand rotation. Like Apple Catch, this is a solo game in which the player has to move and rotate different shapes into their corresponding holes on the screen. Moving a shape is done by pinching a hand while hovering over a shape, then dragging it.

![Apple Catch game screenshot](/assets/img/projects/colored-gloves/pick-n-slot.png)

## Platformer

This is a more complicated game that involes (at least) two players. This game uses the differently colored gloves. The players wear four differently colored gloves which each have a different purpose: The purple glove allows the player to move left and right, the green glove allows the player to jump, and yellow and blue gloves allow the players to move obstacles that have these colors.

![Apple Catch game screenshot](/assets/img/projects/colored-gloves/platformer.jpg)

## Installation

### System Requirements

The application needs to be run on a MacOS or Windows machine. It has been tested on Windows 11 and MacOS Sonoma 14.5 devices. In addition the machine needs to have a working detectable camera. Gloves in the colors blue, green, yellow, and purple are needed (like in the picture at the top of the page, but red is not needed). The game can only be played from the Godot editor, hence Godot 4.3 or higher needs to be installed. Python 3.12 or higher also need to be installed on the system. Commands in the next section may differ based on the installed Python version.

### Installation Instructions

First download the code and unzip it if necessary. Open Godot and press the "Import" button in the top left. Select the `project.godot` file inside the downloaded code folder.

Then open the code folder in a terminal and create a Python virtual environment in a folder named `.env` (this name is important!), using the following command:

```bash
python3.12 -m venv .env
```

Then activate the virtual environment, which is done with `.\.env\Scripts\activate` on Windows and `./.env/bin/activate` on MacOS. Now install the required packages using

```bash
pip install -r requirements.txt
```

The game is now fully set up! Open the project in Godot and press the play button in the top right. The game should now load. Keep in mind that the camera may take a while to load.

Hold a hand in front of the camera to make a cursor (hand) appear. Pinch this hand while hovering over a button to press it. These are the basic controls.