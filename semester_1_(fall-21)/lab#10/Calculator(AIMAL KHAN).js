function calc()
{
    var result;
    var n1= parseInt(document.getElementById("n1").value);
    var n2 = parseInt(document.getElementById("n2").value);
    var oper = document.getElementById("operators").value;
   
    if (oper == "+"){
        result = n1 + n2;
        document.getElementById("result").innerHTMl="The <b>sum</b> is" +result;
    }else if(oper == "-"){
        result = n1 - n2;
        document.getElementById("result").innerHTML="The <b>Subtraction</b> is " +result;
    }else if(oper == "*"){
        result = n1 * n2;
      document.getElementById("result").innerHTML="The <b>Multiplication</b> is " +result;
    }else if(oper == "/"){
        result=n1/n2;
      document.getElementById("result").innerHTML="The <b>Division</b> is " +result;
    }else if(oper == "%"){
        result=n1%n2;
     document.getElementById("result").innerHTML="The <b>Reminder</b> is " +result;    
    }else{
        document.getElementById("result").innerHTML="Invalid Format or Syntax Error!";
    }
}