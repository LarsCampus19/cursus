#!/bin/zsh

# Track the progress of a function in a file

# Request function
echo "What function would you like to see the progression of?"
read FUNCTION

# Extract the function name without the return type (if provided)
FUNCTION_NAME=$(echo $FUNCTION | awk '{print $NF}')

# Search for the function definition in files and retrieve the file name
FILE=$(find . \( -name "*.c" -o -name "*.cpp" \) -not -path "*mlx*" -exec grep -l -E "^[[:alnum:]_]+\s*\**$FUNCTION_NAME" {} \; 2>/dev/null)

# Return an error if no function was found
if [ -z "$FILE" ]; then
    echo "Function '$FUNCTION' not found, check the spelling" >&2
    exit 1
fi

# Run command with the retrieved file name and function name
git log --reverse --pretty=format:"%C(blue)%ar, by: %an (%G?)%n%s%n" -L :$FUNCTION_NAME:$FILE
