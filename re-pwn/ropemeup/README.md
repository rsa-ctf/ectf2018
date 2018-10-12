# Challenge: ropmeup

# Points: 150

# Description: 

Do you know who to get a shell from a rope?

NOTE FOR US: 

2. While setting up, the user of **rop** executable should be **rop** it should be setuid to **rop_pwn**.

3. This is how convert rop into a setuid executable:

a. Create 2 users with names **rop** and **rop_pwn**. .
b. Change the owner of rop-executable to **rop_pwn** - chown rop_pwn rop
c. Change the group of rop-executable to **rop** - chgrp rop rop
d. Set the setuid bit: chmod u+s rop

So, a user with rop prvileges can also run executables with rop_pwn(higher privileges) and get a shell with highe
r privileges to read **flag.txt** .

4. There is a flag.txt with user **rop_pwn** and group **rop_pwn**. So, onlywiththe shell with privileges **chain
me_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **rop_pwn** user is able to read it and no one else
.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-
privilege-users but this should happen in our case.

This is very very important!