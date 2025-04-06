---
layout: post
title: "Confusing Color Names"
date: 2025-04-05 21:00:00 +0200
categories: blog
---

I want to complain about something: Color names in programming languages. Because these are really confusing to me. And to make it even worse: There are dozens of different standards!

It all started while trying to set up the website you're reading this on: I had an element with a `grey` color and wanted to make it darker. So what do I do? I change the color to `darkgrey`. And what do you know? The color becomes lighter! Yeah, really. I've put the colors next to each other below:
<div style="display: flex; flex-direction: row; justify-content: center; margin: 1.5em 0;">
    <div style="width: 5em;">
        <div style="width: 5em; height: 5em; background-color: grey; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">grey</div>
    </div>
    <div style="width: 5em; margin-left: 1em;">
        <div style="width: 5em; height: 5em; background-color: darkgrey; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">darkgrey</div>
    </div>
</div>
So, why? Well it turns out that grey is reserved as the color `rgb(128, 128, 128)`, exactly halfway between `rgb(0, 0, 0)` (black) and `rgb(255, 255, 255)` (white). However, the dark grey color was included from X11, which has grey defined as `rgb(190, 190, 190)` and dark grey defined as `rgb(169, 169, 169)`. Also, by the way, both standards write it as `gray`, which we have America to thank for. Luckily both spellings are allowed in CSS now. And I already complain: If you're writing "grey", shouldn't you also use "colour"? Well, I've got nothing to say about that do I.

You know where you can't write "grey"? In Minecraft. Yes we're talking Minecraft now. Although the forced "gray" spelling is confusing, there is something I'm annoyed by a lot more: Minecraft does not have the color `purple`. It only has `dark_purple` and `light_purple`. And now you can think to yourself: Well then remember to just use the light and dark prefixes everywhere, right? Wrong! Because purple is the only color with a "light" variant. All of the other colors have a base variant and a darker variant, so `green` and `dark_green`. Except for black, white, and yellow for some reason. The darker version of yellow is called `gold`, but looks orange not gold. And by the way: neither green nor dark green has an actual pure green color, because green has is the color `rgb(85, 255, 85)` and dark green is `rgb(0, 170, 0)`, while in reality a pure green color is `rgb(0, 255, 0)`. It's right there in the name: Red, Green, Blue. Are you confused yet? Because I am.

<div style="display: flex; flex-direction: row; justify-content: center; margin: 1.5em 0;">
    <div style="width: 5em;">
        <div style="width: 5em; height: 5em; background-color: #FF55FF; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">light_purple</div>
    </div>
    <div style="width: 5em; margin-left: 1em;">
        <div style="width: 5em; height: 5em; background-color: #AA00AA; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">dark_purple</div>
    </div>
    <div style="width: 5em; margin-left: 1em;">
        <div style="width: 5em; height: 5em; background-color: #FFFF55; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">yellow</div>
    </div>
    <div style="width: 5em; margin-left: 1em;">
        <div style="width: 5em; height: 5em; background-color: #FFAA00; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">gold</div>
    </div>
    <div style="width: 5em; margin-left: 1em;">
        <div style="width: 5em; height: 5em; background-color: #55FF55; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">green</div>
    </div>
    <div style="width: 5em; margin-left: 1em;">
        <div style="width: 5em; height: 5em; background-color: #00AA00; border-radius: .3em;"></div>
        <div style="text-align: center; margin-top: .3em;">dark_green</div>
    </div>
</div>

## My Proposed Solution

I see all of these confusing standards and want to do my part in solving this terrible problem. That's why I'm proposing a new standard to replace all of the existing standards. And I'm not just talking about programming: We need to replace *everything*. Written language, spoken language, everything.

How do we do this? Well we use an already existing, very strong, standard: Hexadecimal codes. In CSS you can write a color as three hexadecimal digits. For example, the color blue is `#00F`, while the color grey is `#777`, which is exactly between `#000` (black) and `#FFF` (white). So we have 16 options for each of the three digits. Then we just match 16 different syllables with each of the digits:

| Digit | Syllable |
| --- | --- |
| `0` | a |
| `1` | be |
| `2` | bi |
| `3` | le |
| `4` | li |
| `5` | la |
| `6` | pi |
| `7` | pa |
| `8` | ge |
| `9` | te |
| `A` | ta |
| `B` | ma |
| `C` | we |
| `D` | o |
| `E` | re |
| `F` | ze |

To make a color, just put three syllables together. So grey will be gegege, and red will be zeaa. Black will be aaa and the Minecraft dark green will be ataa. Just like that we've created 4096 color names! And you can remember them all by remembering 16 syllables. Problem solved!