let g:TargetFile='Foo.cpp'
let g:TargetFlags=''

function! Compile()
  execute '!g++ ' g:TargetFile '-o "TEST"'
endfunction

nnoremap <f5> :call Compile()<cr>
