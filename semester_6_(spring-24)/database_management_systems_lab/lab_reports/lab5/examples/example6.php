<!-- Example 6: Use of Switch Statement  -->
<?php 
    $page = 'Login';
    switch ($page) 
    { 
        case "Home": 
            echo "You selected Home"; 
        break; 
        case "About": 
            echo "You selected About"; 
            break; 
        case "News": 
            echo "You selected News"; 
            break; 
        case "Login": 
            echo "You selected Login"; 
            break; 
        case "Links": 
            echo "You selected Links"; 
            break; 
    } 
?>
