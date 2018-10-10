# Base image
FROM python:2.7-slim

# Challenge author
MAINTAINER hehaichi@gmail.com

# Make sure everything's up-to-date
RUN apt-get update \
# Install dependencies
&&  pip install flask \
# Cleanup
&& rm -rf /var/lib/apt/lists/*

# Create the challenge directory
RUN mkdir -p /home/flag /home/challenge/web

# Move the challenge file into the container
COPY web/ /home/challenge/web/
COPY flag.txt /home/flag/
# Expose the required port
EXPOSE 40005

ENV WERKZEUG_DEBUG_PIN off
RUN useradd noob
USER noob
# Serve
CMD ["python", "/home/challenge/web/service.py"]

# docker build . -t super_secure_service
# docker run -p 40005:40005 super_secure_service