# Challenge: shellco

# Points: 100

# Description: 

Waah! Shellcode!
Look at [this](./shellco) executable. 
[This](./shellco.c) is the sourcefile. 

# Steps: 

1. Read the sourcefile. 
2. Get the vulnerability. 
3. Write shellcode. 
4. Inject Shellcode. 
5. Pwn it!

NOTE TO US:


2. While setting up, the user of **shellco** executable should be **shellco** it should be setuid to **shellco_pwn**.

3. This is how convert shellco into a setuid executable:

a. Create 2 users with names **shellco** and **shellco_pwn**. .
b. Change the owner of shellco-executable to **shellco_pwn** - chown shellco_pwn shellco
c. Change the group of shellco-executable to **shellco** - chgrp shellco shellco
d. Set the setuid bit: chmod u+s shellco

So, a user with shellco prvileges can also run executables with shellco_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **shellco_pwn** and group **shellco_pwn**. So, only withthe shell with privileges **shellco_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **shellco_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case.

This is very very important!
