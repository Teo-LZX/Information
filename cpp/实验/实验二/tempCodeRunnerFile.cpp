int Employee::base_id=1001;
Employee:: Employee(){
    cout << "Input name:";
    cin >> name;
    base_id++;
}
void Employee::display(){
    cout << "ID:" << base_id << " Name:" << name << endl;
}