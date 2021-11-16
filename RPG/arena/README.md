# A simple RPG arena helper

## Available command:

> `A join` : To join the list

> `A leave` : To leave the list

> `A list` : To check the list

> `A reset` : To reset the list (**Mod only command**) 

## Setup process:

> `Command trigger type` : `starts with` 

> `trigger` : `a` 

Copy the whole [main.cc](https://github.com/Shadow21AR/Yag-CC/blob/989a5a84abb62fc0c19d8e80333d82f0e91ef9fc/RPG/arena/main.cc).

## Configurable code:
### **Important configuration**
```go
{{$join := ##### }} {{/* <-- replace ##### with Arena join channel ID */}}
{{$arena := ##### }} {{/* <-- replace ##### with Arena channel ID */}}
{{$mod :=  &&&&&& }} {{/* <-- replace &&&&& with mode role ID */}}
{{$arenaRole := &&&&&& }} {{/* <-- replace &&&&& with role ID that unlocks #arena channel */}}
```

 • give arena list joining channel ID in $join.  

 • give arena channel ID in $arena.  

 • give mod role ID in $mod. (For "A reset").  

 • give Role ID to be given to listed players in $arenaRole.

### **Discord Configuration**

I don't think I need to explain this, but for the sake of README :)
1. Create a private channel `#arena` for arena.
2. Create a role `a list` that can access that channel.

### **Not so Important configuration**
```go
{{$expiryTime := 15}} {{/* time in minutes to reset arena list after being inactive */}}
{{$success := "✅"}}
{{$error := "❌"}}
{{$cookie := "🍪"}}
```
*These are default values, you can change them if you want to, and if you can :)*



> If you find any bug, you can report it to me on discord.  

> You can find me on YAGPDB support server , my User name is `Shadow21A🌟#3030`.  

> **If you find any problem setting this cc on your server, you can ask me on discord, BUT only after u followed the above instructions and still can't set it up.**