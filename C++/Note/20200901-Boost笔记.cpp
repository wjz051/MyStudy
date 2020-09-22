容器相关 (Containers) ：
 boost.any, 万能类型，能保存任意类型值的类，这一点有点像variant类型，不过variant由于采用了一个巨大的union，效率非常低。而boost利用模板，保存的时候并不改变值的类型，只是在需要的时候才提供方法让用户进行类型判断及取值。在传统的C++程序中，为了支持各种数据类型，我们不得不使用万能指针"void *"，但是很遗憾的是，基于万能指针的转换是不安全的，"void*"缺少类型检查。所以，我们建议大家尽量使用any类。
	boost.tuple, 类似pair,存储多种类型。
	boost.array, 定长数组。
	boost.unordered，hash表实现的无序的map和set。
字符串和文字处理 (String & Text Processing) ：
 boost.lexical_cast, 类型转换
	boost::lexical_cast<int>("127")

	boost.format, 采用了与 C 库的 printf 一族函数的风格来控制输出的格式
	cout << boost::format("writing %1%,  x=%2% : %3%-th try") % "toto" % 40.23 % 50; // prints "writing toto,  x=40.230 : 50-th try"
	 
	boost.string_algo，
	string_algo库提供的算法共分五大类，如下:
	1. 大小写转换 to_upper to_lower
	2. 判断式与分类 starts_with ends_with contains equals all 
	3. 修剪 trim_left trim
	4. 查找与替换 find_first find_regex replace/erase_first replace/erase_all
	5. 分割与合井 split join
	
正则表达式 (Regular Expression)
 boost.regex

		. 任意字符;使用match_no_dot_null标志时不匹配NULL字符; 使用match_not_dot_newline时不匹配换行字符
        ^ 匹配行的开始
        $ 匹配行的结束
        * 重复零次或则更多,例如a*b可匹配b,ab,aab,aaaaaaab
        + 重复一次以上，例如a+b可匹配ab,aab,aaaaaaaab。但不能匹配b了
        ? 零次或则一次，例如ca?b匹配cb,cab但不匹被caab    
        a{n} 匹配字符'a'重复n次
        a{n,}，字符a重复n次以上（含n次）
        a{n,m} a重复n到m次（含）
        *?   匹配前一个原子零次以上
        +?   匹配前一个原子一次以上
        ??   匹配前一个原子零次以上
        {n,}?  匹配前一个原子n次以上(含)
        {n,m?  匹配前一个原子n到m次(含)
        | 或操作，例如ab(d|ef)匹配abd或则abef
        [] 字符集操作，例如[abc]将匹配任何单个字符'a'，'b'，'c'
        [a-d]，表示a、b、c、d
        ^否操作，例如[^a-c]表示a至c之外的所有字符
		
智能指针 (Smart Pointers) ：
 boost.smart_ptr
函数对象相关 (Function Objects) ：
 boost.bind, 绑定函数，提供占位符
	boost.mem_fn, 成员函数绑定
	boost.function, 回调函数，可以接受bind返回的函数
	boost.ref, 引用成员
	boost.lambda，
序列化 (Serialization) ：
 boost.serialization
日期与时间 (Date & Time)
 boost.date_time
多线程 (MultiThreads) ：
 boost.thread
网络 (Networking) ：
 boost.asio