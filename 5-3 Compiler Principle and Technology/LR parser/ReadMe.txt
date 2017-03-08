------！！！请注意！！！------


由于本人疏忽，上次上传的LL1分析器中，
没有提供tokens.txt（测试用例输入）这个输入文件。
本次LR分析器提供的的tokens.txt适用于本实验也适用于LL1分析器。
对因疏忽而造成的不必要的麻烦感到抱歉！


------文档说明------


·LRgrammar.py
为本次实验所用的脚本，其文法输入为grammarInput.txt，词串输入为tokens.txt，输出为LRResult.txt

·grammarInput.txt
是本次实验程序的输入。
为了简化，在这里我们规定了文法的格式如下：
-第一个产生式的左部为起始符号
-请将同一个非终结符的产生式写到一行（请注意，在上次LL1实验中未强调）
-非终结符为单个大写字母
-终结符为单个小写字母
-表达式中的伊普西龙符号用#代替
-请按照本文件中的文法格式输入候选式，每个候选式被||包裹（包括首尾）
-按照这种格式的另一个例子请见grammar_test.txt

·tokens.txt
是token串的输入，在这里用字符a来简化词法分析过程，
默认一个a代表一个被词法分析器识别的数字。

·LRResult.txt
是本次实验的输出，包括以下内容：
-Items：LR0项目集规范族
-GO_FOR_DFA：DFA的转移函数
-ACTION TABLE：SLR分析表的ACTION表
-GOTO_TABLE：SLR分析表的GOTO表
-LR Result：针对测试用例的LR分析过程输出。
具体格式约定请见设计文档。

·get_FIRST_SET_AND_FOLLOW_SET.py
是根据实验中的求解FIRST集合FOLLOW集制作的通用求解脚本。
请将测试文法输入至grammar_test.txt中，运行脚本，输出请见FIRST_AND_FOLLOW_SET.txt

·grammar_test.txt
求解器脚本的输入，请按照上述格式输入测试文法

·FIRST_AND_FOLLOW_SET.txt
求解器脚本的输出，其中包括测试文法的FIRST集和FOLLOW集

·LR语法分析程序——设计文档.docx
本次实验的设计文档。


---

如有问题请与我联系，谢谢！

史文翰
No.2014211218
Cla.2014211304
shiwenhan@bupt.edu.cn

12.19
	