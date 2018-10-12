# Challenge: sof1

# Points: 75

# Description: 

Do you know Control Flow Hijacking?
Look at [this](./sof1) executable. 
[This](./sof1.c) is the sourcefile. 

# Steps: 

1. Read the sourcefile. 
2. Get the vulnerability. 
3. Write the exploit. 
4. Pwn it!

NOTE TO US:

2. While setting up, the user of **sof1** executable should be **sof1** it should be setuid to **sof1_pwn**.

3. This is how convert sof1 into a setuid executable:

a. Create 2 users with names **sof1** and **sof1_pwn**. .
b. Change the owner of sof1-executable to **sof1_pwn** - chown sof1_pwn sof1
c. Change the group of sof1-executable to **sof1** - chgrp sof1 sof1
d. Set the setuid bit: chmod u+s sof1

So, a user with sof1 prvileges can also run executables with sof1_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **sof1_pwn** and group **sof1_pwn**. So, only withthe shell with privileges **sof1_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **sof1_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case.

This is very very important!
