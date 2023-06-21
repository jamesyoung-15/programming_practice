/* Javascript Practice */

// Dice roll
document.getElementById("buttonClick").onclick = function(){
    let x = Math.floor(Math.random()*6) + 1;
    let y = Math.floor(Math.random()*6) + 1;
    let z = Math.floor(Math.random()*6) + 1;

    document.getElementById("xLabel").innerHTML = x;
    document.getElementById("yLabel").innerHTML = y;
    document.getElementById("zLabel").innerHTML = z;

}

// number guessing
const TARGETNUM = Math.floor(Math.random()*10) + 1;
let numGuesses = 0;
document.getElementById("checkGuess").onclick = function(){
    let guess = document.getElementById("numberGuess").value;
    console.log(`Target: ${TARGETNUM}`);
    console.log(`Guess: ${guess}`)
    if(guess==TARGETNUM){
        numGuesses++;
        alert(`Correct! The number was ${TARGETNUM}. It took ${numGuesses} attempts.`)
        numGuesses = 0;
    }
    else if(guess>TARGETNUM){
        alert("Too large.")
        numGuesses++;
    }
    else{
        alert("Too small.")
        numGuesses++;
    }
}

// classes

class Person{
    constructor(name, age){
        this.name = name;
        this.age = age;
    }
}

class Employee extends Person{
    constructor(name,age,job,wage){
        super(name,age);
        this.job = job;
        this.wage = wage;
    }
}

let guy = new Employee("James",21,"Student",0);

console.log(guy.age);

// Error handling

try{
    let x = window.prompt("Enter a number: ");
    x = Number(x);

    if(isNaN(x)) throw "Not a number";

    if(x=="") throw "That was empty";

    console.log(`${x} is a number`);
}
catch(error){
    console.log(error);
}

// Setup
const recordCollection = {
    2548: {
      albumTitle: 'Slippery When Wet',
      artist: 'Bon Jovi',
      tracks: ['Let It Rock', 'You Give Love a Bad Name']
    },
    2468: {
      albumTitle: '1999',
      artist: 'Prince',
      tracks: ['1999', 'Little Red Corvette']
    },
    1245: {
      artist: 'Robert Palmer',
      tracks: []
    },
    5439: {
      albumTitle: 'ABBA Gold'
    }
  };
  
// Setup
const contacts = [
    {
      firstName: "Akira",
      lastName: "Laine",
      number: "0543236543",
      likes: ["Pizza", "Coding", "Brownie Points"],
    },
    {
      firstName: "Harry",
      lastName: "Potter",
      number: "0994372684",
      likes: ["Hogwarts", "Magic", "Hagrid"],
    },
    {
      firstName: "Sherlock",
      lastName: "Holmes",
      number: "0487345643",
      likes: ["Intriguing Cases", "Violin"],
    },
    {
      firstName: "Kristian",
      lastName: "Vos",
      number: "unknown",
      likes: ["JavaScript", "Gaming", "Foxes"],
    },
  ];
  