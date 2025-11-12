if [ -d "ag-ffi-header/.git" ]; then
    git -C "ag-ffi-header" fetch
else
    git clone https://github.com/kota-codex/ag-ffi-header.git
fi
