# Challenge: sof0

# Points: 50

# Description:

What is an overflow??
Look at [this](./sof0) executable.
[This](./sof0.c) is the sourcefile.

# Hint:

1. Read the sourcefile properly.




NOTE TO US:


2. While setting up, the user of **sof0** executable should be **sof0** it should be setuid to **sof0_pwn**.

3. This is how convert sof0 into a setuid executable:

a. Create 2 users with names **sof0** and **sof0_pwn**. .
b. Change the owner of sof0-executable to **sof0_pwn** - chown sof0_pwn sof0
c. Change the group of sof0-executable to **sof0** - chgrp sof0 sof0
d. Set the setuid bit: chmod u+s sof0

So, a user with sof0 prvileges can also run executables with sof0_pwn(higher privileges) and get a shell with higher privileges to read **flag.txt** .

4. There is a flag.txt with user **sof0_pwn** and group **sof0_pwn**. So, only withthe shell with privileges **sof0_pwn**, one will be able to read flag.txt.

5. With tha flag.txt, the following should be done to ensure only **sof0_pwn** user is able to read it and no one else.

$ sudo chmod 0400 flag.txt  - Damn Important because in normal cases, "others" are allowed to read files owned by higher-privilege-users but this should happne in our case.

This is very very important!
