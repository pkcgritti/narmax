nnoremap <leader>lv :vsplit .vimrc<cr>
nnoremap <leader>ls :source .vimrc<cr>
nnoremap <leader>mv :vsplit .maketest<cr>
nnoremap <f5> :!clear && make -f .maketest<cr>
autocmd BufNewFile,BufRead .maketest set syntax=make
