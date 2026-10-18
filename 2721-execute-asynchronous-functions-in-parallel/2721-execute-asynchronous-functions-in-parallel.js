function promiseAll(functions) {
	return new Promise(async (resolve, reject) => {
		const promises = functions.map((fn) =>
			fn().then(
				(value) => ( value ),
				(error) => {
					reject(error)
					return { }
				},
			),
		)

		const results = []

		for await (const result of promises) {
			results.push(result)
		}

		resolve(results)
	})
}