<!-- Inheritance allows one class to inherit the methods and properties of another class. We use the extends keyword. -->

<?php
class Vehicle {
    public $brand;
    public function __construct($brand) {
        $this->brand = $brand;
    }

    public function start() {
        return "Starting the engine...";
    }
}

class Motorcycle extends Vehicle {
    public function wheelie() {
        return "Performing a wheelie!";
    }
}

$motorcycle = new Motorcycle("Harley-Davidson");
echo $motorcycle->start(); // Outputs: Starting the engine...
echo $motorcycle->wheelie(); // Outputs: Performing a wheelie!
?>
