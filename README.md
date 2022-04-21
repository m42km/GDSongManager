# GDSongManager
Install songs into Geometry Dash easily. Built in C++ and packaged with [Inno Setup](https://jrsoftware.org/isinfo.php)

## Software Installation Guide
**Recommended installation** - Download the Inno Setup installer @ the latest release and run it. 

If your antivirus conflicts with your installation then make an exception for the installer executable, after that make an exception for `songinst.exe` in the directory that you installed GDSM in as well.

**Manual installation** -  Follow these steps:

- Download songinst.exe
- Download and open the test .gdsong file in the releases
- This should show up: 
![image](https://user-images.githubusercontent.com/78104595/164455725-7b9c657e-7d95-4d17-8f22-aca98881ecf2.png)

- Press more apps, then scroll down for look for more apps on this PC and then go to songinst.exe

## NONG Installation

Click on a NONG and let GDSM do its magic. The window will close after a couple of seconds, after that just exit out of and go back in the level. If it doesn't show up then restart Geometry Dash if needed. If it still doesn't work then [open an issue here](https://github.com/m42km/GDSongManager/issues) with the name of your operating system.

## Making a NONG compatible with GDSM

Make sure that you have "File name extensions" visible in File Explorer (This is what it should look like in Windows 11):

![image](https://user-images.githubusercontent.com/78104595/164332522-91080af4-a844-445a-b206-6ba2df09266c.png)

Ensure that the song is converted to the mp3 format, then rename the filename extension from `.mp3` to `.gdsong`. 

*The song ID should be the only thing before the `.gdsong` extension.*
