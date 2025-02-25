#!/bin/bash

TMP_OUTPUT=$(mktemp)

remove_comments() {
    local input_file="$1"
    local relative_path="${input_file#./}"
    local file_ext="${input_file##*.}"
    
    # libftディレクトリはスキップ
    if [[ "$input_file" == *"/lib/libft/"* ]]; then
        return
    fi
    
    {
        echo "----------------------------------------"
        echo "File: $relative_path"
        echo "----------------------------------------"
        
        if [[ "$relative_path" == *"Makefile"* ]]; then
            sed 's/#.*$//' "$input_file" | awk 'NF'
        else
            sed '/\/\*.*\*\//d; /\/\*.*/,/.*\*\//d; s/\/\/.*//' "$input_file" | awk 'NF'
        fi
        
        echo "----------------------------------------"
        echo
    } >> "$TMP_OUTPUT"
}

tree >> "$TMP_OUTPUT"
find src tests Makefile -type f \( -name "*.c" -o -name "*.h" -o -name "Makefile" \) | while read -r file; do
    remove_comments "$file"
done

cat "$TMP_OUTPUT" | pbcopy
rm "$TMP_OUTPUT"
