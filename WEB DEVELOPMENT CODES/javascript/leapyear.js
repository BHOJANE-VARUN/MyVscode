function leap(num) {
    if(num%4==0)
    {
        if(num%100==0)
        {   
            if(num%400==0)
            console.log("leap year");
            else console.log("not a leap year");
        }
        else{
            console.log("leap year");
        }
    }
    else{
        console.log("not a leap year");
    }
}
var n = 2000;
leap(n);