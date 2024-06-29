<!-- Example 4: Setting Variable to Different Types  -->
<?php
    $test_var = 8.23; 
    echo $test_var . " < br / > "; // Displays “8.23” 
    settype( $test_var, "string" ); 
    echo $test_var . " < br / > "; // Displays “8.23” 
    settype( $test_var, "integer" ); 
    echo $test_var . " < br / > "; // Displays “8” 
    settype( $test_var, "float" ); 
    echo $test_var . " < br / > "; // Displays “8” 
    settype( $test_var, "boolean" ); 
    echo $test_var . " < br / > "; // Displays “1” 
?>