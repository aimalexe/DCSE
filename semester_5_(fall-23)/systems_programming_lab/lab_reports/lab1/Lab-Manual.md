## Lab 1: Unix Commands Overview

This lab is about the different commands of Linux for personal use. Editing, compiling,
and executing the C programs.
- Read the man pages for the following commands (write man [command] on 
terminal, press q to exit man): 
   1. script
   2. `finger`,` who`, `w`
   3. `touch`
   4. `top` 
   5. `mkdir`
   6. `umask`: umask [value] (shell built in command) 
   7. text utilities: `sort`, `uniq`, `tr`,` expand`, `unexpand`, `cut`. 
   8. `gcc`
   9. `history`
   10. `grep`
   11. `awk`
   12. `ps`
   13. `echo`

- In your home directory create the subdirectory `~/cse302/labs/lab1` . (Use multiple `mkdir` commands or consult the `-p` option for `mkdir` in the man page for `mkdir`). 
   1. cd `~/cse302/labs/lab1`
   2. Copy or create a file named myfile into `~/cse302/labs/lab1` (if you create it, type something into it). For information on how to create a quick empty file, `man touch`. 
   3. Create a soft link soft_link and a hard link hard_link to that file. 
   4. Based on the output returned by stat and `ls` commands (using all relevant options), explain in detail (but briefly) the differences between the three files.

- Create a script and show how many usernames have logged in use pipelining, `grep` and who command also investigate wc in man.
- Change your file permission mask such that by default your colleagues do not have read permissions for your newly created files. Please show in the transcript file the following: 
  1. the initial mask 
  2. how you changed it 
  3. show that people in your user group don't have read permissions for a new file you're creating.
  4. Change the umask permanently by placing the umask command in your .bash_profile file.
   
- List the PIDs of all processes running as root on your computer on a line, separated by commas. E.g., 1,2,3,4,5,657,658, ... Use pipes to create a one-line command that this. You'll need some of the text processing tools presented in class. Hint: `man ps` (`-a` and `-x` flags), `man tr`. 

- List the usernames and names of the people logged on the list returned should be 
sorted and should have the following format: 
``` html
1 <username1> <Time>
2 <username2> <Time>
3 <username3> <Time>
``` 
Hint: use the `nl` command to number lines.