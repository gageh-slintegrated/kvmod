# KVM Mod

# Hardware
* (2) [PWAY HDMI USB KVM SWITCH 2X1](https://www.amazon.com/AAO-Supports-Auto-scan-Hot-Key-Netware/dp/B07NZMM2PK/ref=sr_1_3?dchild=1&keywords=PWAY+HDMI+USB+KVM+SWITCH+2X1&qid=1586721640&s=electronics&sr=1-3)
* (1) Arduino UNO (or other...)
* (1) Arduino Relay Module

## Physical Modification
![alt text](./docs/pcb_top.jpg "PCB Top")
![alt text](./docs/pcb_bottom.jpg "PCB Bottom")

* PC 1 and PC 2 LED voltage is used to determine what channel the kvm is currently switched to
* Ground is... ground :)
* The switch leg will be connected to a discrete relay for remote switching.

## Software
* Very simple arduino code. If KVM #2 is not on the same channel as KVM #1, change KVM #2s channel to get them in sync
* Once they're in sync, when the switch is pressed change both KVMs to the same channel.