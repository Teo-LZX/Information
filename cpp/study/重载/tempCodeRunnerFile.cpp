 void operator=(Person& p){
            if(age != NULL){
                delete age;
                age = NULL;
            }
            age  = new int(*p.age);
        }