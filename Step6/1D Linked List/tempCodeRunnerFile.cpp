  while(mover != nullptr){
        if(mover->data == searchValue){
            found = true; 
            break; 
        }
        mover = mover->next; 
    }