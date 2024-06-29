<!-- Polymorphism is the ability of different classes to be treated as instances of the same class through inheritance. It includes the concept of overriding inherited methods and interfaces. -->

<?php
interface Animal {
    public function makeSound();
}

class Dog implements Animal {
    public function makeSound() {
        return "Bark";
    }
}

class Cat implements Animal {
    public function makeSound() {
        return "Meow";
    }
}

function animalSound(Animal $animal) {
    echo $animal->makeSound();
}

$dog = new Dog();
$cat = new Cat();

animalSound($dog); // Outputs: Bark
animalSound($cat); // Outputs: Meow
?>
