int main()
{
    char str[81];
    printf("Введите строку до 80 символов: ");
    fgets(str, 81, stdin);
    printf("Исходная строка: %s", str);
    
    int i = 0;
    while(str[i] != '\0')
    {
    
        if(str[i] == 'a')
        {
            str [i] = 'A';
        }
        else if(str [i] == 'b')
        {
            str [i] = 'B';
        }
        i++;
    }
    
    return 0;
}