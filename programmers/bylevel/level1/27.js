function solution(arr1, arr2) {
  // answer 배열 선언
  let answer = [];
  for (let i = 0; i < arr1.length; i++) {
    //answer에 넣을 배열 nowarr 선언
    let nowarr = [];
    for (let j = 0; j < arr1[0].length; j++) {
      //[4,6]
      //nowarr에 원소 추가
      nowarr.push(arr1[i][j] + arr2[i][j]);
    }
    //만든 nowarray를 answer에 추가
    answer.push(nowarr);
  }
  return answer;
}
//arr1: [[1,2,3],[2,3,4]]
//arr1.length=2;
//arr1[0].length =3;

//위의 예시의 경우
//루프를 돌면서
//초기 answer =[];
//nowarr=[1,2,3]을 만들고 answer에 삽임, 그 결과 answer = [[1,2,3]]
//nowarr=[2,3,4]를 만들고 answer에 삽입, 그 결과 answer = [[1,2,3],[1,2,3]]

//(i,j) 인덱싱
//[ [(0,0),(0,1),(0,2)],
// [(1,0),(1,1),(1,2)] ]
