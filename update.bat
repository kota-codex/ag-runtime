if exist "ag-ffi-header\.git" (
    git -C "ag-ffi-header" fetch
) else (
    git clone "https://github.com/kota-codex/ag-ffi-header.git"
)
