# Challenge: GameOfThrones

# Points: 75

# Description: 

Do you know GOT??

2. While setting up, the user of **got** executable should be **got** it should be setuid to **got_pwn**.

3. This is how convert got into a setuid executable:

a. Create 2 users with names **got** and **got_pwn**. .
b. Change the owner of got-executable to **got_pwn** - chown got_pwn got
c. Change the group of got-executable to **got** - chgrp got got
d. Set the setuid bit: chmod u+s got

So, a user with got prvileges can also run executables with got_pwn(higher privileges) and get a shell with highe
r privileges to read **flag.txt** .

4. There is a flag.txt with user **got_pwn** and group **got_pwn**. So, onlywiththe shell with privileges **chain
me_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **got_pwn** user is able to read it and no one else
.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-
privilege-users but this should happen in our case.

This is very very important!