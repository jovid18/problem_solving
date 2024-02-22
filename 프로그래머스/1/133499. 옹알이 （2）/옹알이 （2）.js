function solution(babbling) {
  let validCount = 0;
  const patterns = ["aya", "ye", "woo", "ma"];

  babbling.forEach((word) => {
    let isValid = true;
    let replacedWord = word;

    patterns.forEach((pattern, index) => {
      const regex = new RegExp(pattern, "g");
      replacedWord = replacedWord.replace(regex, index.toString());
    });

    const numArray = Array.from(replacedWord).map((char) => parseInt(char, 10));

    numArray.forEach((num, i) => {
      if (isNaN(num) || (i > 0 && num === numArray[i - 1])) {
        isValid = false;
      }
    });

    if (isValid) validCount++;
  });

  return validCount;
}

