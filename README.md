```
              :::      ::::::::               _       _                 _   _     
            :+:      :+:    :+:     _ __ ___ (_)_ __ (_)___ _   _ _ __ | |_| |__  
          +:+ +:+         +:+      | '_ ` _ \| | '_ \| / __| | | | '_ \| __| '_ \ 
        +#+  +:+       +#+         | | | | | | | | | | \__ \ |_| | | | | |_| | | |
      +#+#+#+#+#+   +#+            |_| |_| |_|_|_| |_|_|___/\__, |_| |_|\__|_| |_|
           #+#    #+#                                       |___/                 
          ###   ########.fr                     By: jgarcia <jgarcia@student.42.fr>
```
# MiniSynth ![C89](https://img.shields.io/badge/C-89-green) ![MiniLibX](https://img.shields.io/badge/Minilibx-linux-green) ![PortAudio](https://img.shields.io/badge/PortAudio-v19-green) ![GPL](https://img.shields.io/github/license/corecaps/MiniSynth?color=green)
Realtime Synthesizer using PortAudio and MinilibX

## Dependecies 

### for Minilibx 
  - gcc
  - Make
  - X11 include files (package xorg)
  - XShm extension (package libxext-dev)
  - Utility functions from BSD Systems (package libbsd-dev)
```
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```
### for Portaudio 
  - ALSA Development Kit
```
sudo apt-get install libasound-dev
```