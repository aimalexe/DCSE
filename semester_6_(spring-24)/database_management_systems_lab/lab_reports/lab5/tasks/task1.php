<?php
    $test_var = 8.23;

    // Casting to integer
    $int_var = (int)$test_var;
    echo "Integer: " . $int_var . "<br>";

    // Casting to string
    $str_var = (string)$test_var;
    echo "String: " . $str_var . "<br>";

    // Casting to Boolean
    $bool_var = (bool)$test_var;
    echo "Boolean: " . ($bool_var ? 'true' : 'false') . "<br>";
?>
