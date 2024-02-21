function solution(arr1, arr2) {
  // answer 배열 선언
  let answer = [];
  for (let i = 0; i < arr1.length; i++) {
    //answer에 넣을 배열 nowarr 선언
    let nowarr = [];
    for (let j = 0; j < arr1[0].length; j++) {
      //[4,6],[7,9]
      //nowarr에 원소 추가
      nowarr.push(arr1[i][j] + arr2[i][j]);
    }
    //만든 nowarray를 answer에 추가
    answer.push(nowarr);
  }
  return answer;
}

let arr1 = [
  [
    [1, 2],
    [3, 4],
  ],
  [
    [4, 2],
    [3, 4],
  ],
];
let arr2 = [
  [
    [1, 2],
    [3, 4],
  ],
  [
    [4, 2],
    [3, 4],
  ],
];
