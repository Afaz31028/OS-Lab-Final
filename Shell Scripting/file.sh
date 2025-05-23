read -p "Enter a filename: " filename


if [ -z "$filename" ]; then
    echo "Filename cannot be empty."
    exit 1
fi


if [ ! -e "$filename" ]; then
    touch "$filename"
    echo "File '$filename' was created."
else
    echo "File '$filename' already exists and will be edited."
fi


if [ ! -x "$filename" ]; then
    chmod +x "$filename"
    echo "Execute permission added to '$filename'."
else
    echo "'$filename' already has execute permission. No changes needed."
fi


if command -v nano &> /dev/null; then
    nano "$filename"
elif command -v vim &> /dev/null; then
    vim "$filename"
else
    echo "No suitable editor found (nano or vim)."
    exit 1
fi
