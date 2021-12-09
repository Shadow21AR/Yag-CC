# A simple RPG Boosted MiniBoss helper v1

#

## Trigger:
### `Trigger type` : `starts with` 
### `trigger` : `mb` 

Copy the [main.cc](https://github.com/Shadow21AR/Yag-CC/blob/1993e5335b441ee599d0e6c13bed6ed87fb01dca/RPG/miniboss/mb.go) to dashboard and configure the top part of the code.
#

## Configurable code: 
### **Important configuration**
```go
{{$join := ############### }} {{/* <-- replace ##### with Miniboss join channel ID */}}
{{$mb := ############### }} {{/* <-- replace ##### with Minoboss channel ID */}}
{{$mod := &&&&&&&&&&&&&&&&  }} {{/* <-- replace &&&&& with mode role ID */}}
{{$mbRole := &&&&&&&&&&&&&&&& }} {{/* <-- replace &&&&& with role ID that unlocks #miniboss channel */}}
```

 • give miniboss list joining channel ID in $join.  

 • give miniboss channel ID in $mb.  

 • give mod role ID in $mod. (For "mb reset").  

 • give Role ID to be given to listed players in $mbRole.
#
### **Discord Configuration**

I don't think I need to explain this, but for the sake of README :)
1. Create a private channel `#Miniboss` for boosted arena.
2. Create a role `Role` that can access that channel.
#
### **Not so Important configuration**
```go
{{$expiryTime := 10}} {{/* time in MINUTES to reset arena list after being inactive */}}
{{$skull := "💀"}}
{{$crown := "👑"}}
```
*These are default values, you can change them if you want to, and if you can :)*
#
## Available command:

> `mb join L#` : To join the list

> `mb leave` : To leave the list

> `mb list` : To check the list

> `mb hide` : To manually remove role/Hide arena channnel (By User).

> `mb reset` : To reset the list (**Mod only command**) 

# 
*If you find any bug, you can report it to me on discord.*

*You can find me on YAGPDB support server , my User name is `Shadow21A🌟#3030`.*

**If you find any problem setting this cc on your server, you can ask me on discord, BUT only after u followed the above instructions and still can't set it up.**
