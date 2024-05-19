#!/bin/bash
# Author: Luke Chikkala

# Man Page
usage() {
    echo "Usage: $0 [ToLocal|FromLocal] filename"
    exit 1
}

# Check if correct number of arguments is given
if [ $# -ne 2 ]; then
    usage
fi

# Set direction and filename from arguments
direction="$1"
filename="$2"

# Specify the remote machine details (change these according to your setup)
remote_user="chikkala"
remote_host="192.168.178.46"
remote_path="/home/chikkala/Documents/TempDropOff/*"
local_path="C:\dev_local\TempDropOff\*"

# Function to copy to local machine
copy_to_local() {
    scp "${remote_user}@${remote_host}:${remote_path}/${filename}" "${local_path}/${filename}"
}

# Function to copy from local machine
copy_from_local() {
    scp "${local_path}/${filename}" "${remote_user}@${remote_host}:${remote_path}/${filename}"
}

# Handling the direction of the copy
case $direction in
    "ToLocal")
        copy_to_local
        ;;
    "FromLocal")
        copy_from_local
        ;;
    *)
        echo "Invalid direction. Use 'ToLocal' or 'FromLocal'."
        usage
        ;;
esac
