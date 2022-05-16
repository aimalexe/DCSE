function submitt(){
    var name, dob, regno, usrnm, gender;
    
    name = document.getElementById("name").value;
    document.getElementById("p1").innerHTML=name;
    
    dob = document.getElementById("dob").value;
    document.getElementById("p2").innerHTML=dob;
    
    regno = document.getElementById("regno").value;
    document.getElementById("p3").innerHTML=regno;
    
    usrnm = document.getElementById("usrnm").value;
    document.getElementById("p4").innerHTML=usrnm;
    
    gender = document.getElementById("gender").value;
    document.getElementById("p5").innerHTML=gender;
}