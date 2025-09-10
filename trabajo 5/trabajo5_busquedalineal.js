const arreglo = [5, 8, 3, 10, 7, 2, 15, 9];

// Para leer la entrada del usuario en Node.js, usamos 'readline'
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

readline.question('Ingrese el número a buscar: ', (input) => {
  const elemento = parseInt(input);
  let encontrado = false;

  for (let i = 0; i < arreglo.length; i++) {
    if (arreglo[i] === elemento) {
      console.log(`Elemento ${elemento} encontrado en la posición ${i}.`);
      encontrado = true;
      break; // Detener búsqueda al encontrar el elemento
    }
  }

  if (!encontrado) {
    console.log(`Elemento ${elemento} no encontrado en el arreglo.`);
  }

  readline.close();
});

