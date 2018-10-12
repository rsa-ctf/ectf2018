# Challenge: chainme

# Points: 125

# Description: 

Do you know how to chain stuff?

Look at [this](./chainme) executable. 
[This](./chainme.c) is the sourcefile. 

# Hint: 

Do you know how a function call happens??


NOTE to us: 

2. While setting up, the user of **chainme** executable should be **chainme** it should be setuid to **chainme_pwn**.

3. This is how convert chainme into a setuid executable:

a. Create 2 users with names **chainme** and **chainme_pwn**. .
b. Change the owner of chainme-executable to **chainme_pwn** - chown chainme_pwn chainme
c. Change the group of chainme-executable to **chainme** - chgrp chainme chainme
d. Set the setuid bit: chmod u+s chainme

So, a user with chainme prvileges can also run executables with chainme_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **chainme_pwn** and group **chainme_pwn**. So, onlywiththe shell with privileges **chainme_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **chainme_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case.

This is very very important!
