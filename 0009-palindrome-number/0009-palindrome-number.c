bool isPalindrome(int x) {
    unsigned int rev=0;
    int digit=0,p=x;

    if( p < 0)
    {
        return false;
    }
    while(x != 0)
    {
        digit = x%10;
        rev = (rev*10)+digit;
        x = x/10;
    }

    if(p == rev)
    {
        return true;
    }
    return false;
   
    
}