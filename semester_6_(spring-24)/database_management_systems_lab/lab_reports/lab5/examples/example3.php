<!-- Example 3: Testing Variable Type Using gettype()  -->
<?php    
    $test_var;
    echo gettype( $test_var ) . " < br / > "; // Displays “NULL” 
    $test_var = 15; 
    echo gettype( $test_var ) . " < br / > "; // Displays “integer” 
    $test_var = 8.23; 
    echo gettype( $test_var ) . " < br / > "; // Displays “double” 
    $test_var = "Hello, world!"; 
    echo gettype( $test_var ) . " < br / > "; // Displays “string” 
?>