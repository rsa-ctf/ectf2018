# Base image
FROM python:2.7-slim

# Challenge author
MAINTAINER kaushikskalmady@yahoo.in

# Make sure everything's up-to-date
RUN apt-get update \
&& pip install flask \
&& rm -rf /var/lib/apt/lists/*



# Create the challenge directory
RUN mkdir -p /home/challenge /home/challenge/chal

# Move the challenge file into the container
COPY chal/ /home/challenge/chal

WORKDIR /home/challenge/chal
# Expose the required port
EXPOSE 40050

# Serve
CMD ["python", "-u", "service.py"]

# docker build . -t boostr
# docker run -p 40050:40050 boostr
