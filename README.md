# Colibri

**A media player that can step backwards one frame at a time.**

Every player can step forwards. Almost none can step back, because going
backwards means decoding the whole group of pictures again to reach the frame
just before the one on screen. Colibri keeps recently decoded frames in memory
instead, so stepping back is the same instant operation as stepping forward.

It is for looking closely at video: finding the frame where something happens,
pulling a clean still out of a moving shot, checking a cut.

Colibri is a fork of [VLC](https://www.videolan.org/vlc/).

## Download

Windows 64 bit builds are on the
[releases page](https://github.com/drewzilla37/Colibri/releases/latest).

Portable, no installer. Unzip anywhere and run `colibri.exe`. The build is
unsigned, so SmartScreen warns on first launch: choose **More info**, then
**Run anyway**.

Settings live in `%APPDATA%\colibri`, separate from VLC's, so having both
installed is fine and neither disturbs the other.

## Using it

| Key | Action |
| --- | --- |
| <kbd>E</kbd> | Step forward one frame |
| <kbd>Shift</kbd> + <kbd>E</kbd> | Step backward one frame |

Both work while paused. Pressing either during playback pauses first, and the
next press steps.

How much history is kept is set by **Reverse frame history size** in
Preferences, under *Input / Codecs*. The default is 1024 MB, which is about 85
frames at 4K or several hundred at 1080p.

Frames enter the buffer as they are decoded, so a moment of playback is needed
before there is anything to step back through.

## What works

| | |
| --- | --- |
| **Windows** | Tested, on NVIDIA hardware decoding and on software decoding |
| **AMD and Intel GPUs** | Untested rather than known broken, for want of the hardware |
| **macOS and Linux** | Not built |

## Building

Colibri builds the same way VLC does; see [README.VLC](README.VLC). It is a VLC
fork, so the full VLC build documentation applies.

## Licence and relationship to VLC

Colibri is built on VLC, by the VideoLAN project and its contributors, and is
released under the same GNU General Public License version 2 or later. See
[COPYING](COPYING).

It is not affiliated with or endorsed by VideoLAN. VLC and VideoLAN are their
trademarks. Nearly all the code here is theirs; the frame history and the
rebranding are the part that is not, and the commit history shows exactly which
is which.
