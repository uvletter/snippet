var momerizer = function(memo, formula){
	var recur = function(n){
		var result = memo[n];
		if (typeof result !== 'number'){
			result = formula(recur, n);
			memo[n] = result;
		}
		return result;
	}
	return recur;
};

var fibonacci = momerizer([0,1], function(recur, n){
	return recur(n-1) + recur(n-2);
});

console.log(fibonacci(10));

var demo = function(){
	i=1;
	//var i;
	console.log('In function i is ' + i);
};
demo();
console.log('Out of function i is ' + i);