//
//  NSMutableAttributedString+SCRAttributedStringBuilder.h
//  SCRAttributedStringBuilder
//
//  Created by Chuanren Shang on 2018/4/21.
//  Copyright © 2018 Chuanren Shang. All rights reserved.
//

#import <UIKit/UIKit.h>

// 原理说明：
// 将方法分为 Content，Range 和 Attribute 三类，其中 Content 用于添加内容，Attribute 用于给内容应用属性，而 Range 用于调整应用范围。
// 因此，在 Content 中，无论是 append 还是 insert，会将当前 Range 切换成新加入内容的，属性会应用在此 Range 上。
// 由于属性主要用于应用在字符上，因此附件不会切换 Range。另外为了应对 match 到多个的情况，Range 是一个数组。

@interface NSMutableAttributedString (SCRAttributedStringBuilder)

#pragma mark - Content

// 创建一个 Attributed String
@property (nonatomic, copy, class, readonly) NSMutableAttributedString *(^build)(NSString *string);

// 尾部追加一个新的 Attributed String
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^append)(NSString *string);

// 同 append 比，参数是 NSAttributedString
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^attributedAppend)(NSAttributedString *attributedString);

// 插入一个新的 Attributed String
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^insert)(NSString *string, NSUInteger index);

// 增加间隔，spacing 的单位是 point。放到 Content 的原因是，间隔是通过空格+字体模拟的，但不会导致 Range 的切换
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^appendSpacing)(CGFloat spacing);

// 尾部追加一个附件。同插入字符不同，插入附件并不会将当前 Range 切换成附件所在的 Range，下同
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^appendAttachment)(NSTextAttachment *attachment);

// 在尾部追加图片附件，默认使用图片尺寸，图片垂直居中，为了设置处理垂直居中（基于字体的 capHeight），需要在添加图片附件之前设置字体
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^appendImage)(UIImage *image);

// 在尾部追加图片附件，可以自定义尺寸，默认使用图片前一位的字体进行对齐，其他同 appendImage
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^appendSizeImage)(UIImage *image, CGSize imageSize);

// 在尾部追加图片附件，可以自定义想对齐的字体，图片使用自身尺寸，其他同 appendImage
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^appendFontImage)(UIImage *image, UIFont *font);

// 在尾部追加图片附件，可以自定义尺寸和想对齐的字体，其他同 appendImage
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^appendCustomImage)(UIImage *image, CGSize imageSize, UIFont *font);

// 在 index 位置插入图片附件，由于不确定字体信息，因此需要显式输入字体
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^insertImage)(UIImage *image, CGSize imageSize, NSUInteger index, UIFont *font);

// 同 insertImage 的区别在于，会在当前 Range 的头部插入图片附件，如果没有 Range 则什么也不做
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^headInsertImage)(UIImage *image, CGSize imageSize, UIFont *font);

#pragma mark - Range

// 根据 start 和 length 设置范围
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^range)(NSInteger location, NSInteger length);

// 将范围设置为当前字符串全部
@property (nonatomic, copy, readonly) NSMutableAttributedString *all;

// 匹配所有符合的字符串
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^match)(NSString *string);

// 从头开始匹配第一个符合的字符串
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^matchFirst)(NSString *string);

// 为尾开始匹配第一个符合的字符串
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^matchLast)(NSString *string);

#pragma mark - Basic

// 字体
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^font)(UIFont *font);

// 字号，默认字体
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^fontSize)(CGFloat fontSize);

// 字体颜色
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^color)(UIColor *color);

// 字体颜色，16 进制
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^hexColor)(NSInteger hex);

// 背景颜色
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^backgroundColor)(UIColor *color);

#pragma mark - Glyph

// 删除线风格
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^strikethroughStyle)(NSUnderlineStyle style);

// 删除线颜色
// 由于 iOS 的 Bug，删除线在 iOS 10.3 中无法正确显示，需要配合 baseline 使用
// 具体见：https://stackoverflow.com/questions/43074652/ios-10-3-nsstrikethroughstyleattributename-is-not-rendered-if-applied-to-a-sub
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^strikethroughColor)(UIColor *color);

// 下划线风格
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^underlineStyle)(NSUnderlineStyle style);

// 下划线颜色
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^underlineColor)(UIColor *color);

// 字形边框颜色
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^strokeColor)(UIColor *color);

// 字形边框宽度
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^strokeWidth)(CGFloat width);

// 字体效果
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^textEffect)(NSString *effect);

// 阴影
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^shadow)(NSShadow *shadow);

// 链接
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^link)(NSURL *url);

#pragma mark - Paragraph

// 行间距
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^lineSpacing)(CGFloat spacing);

// 段间距
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^paragraphSpacing)(CGFloat spacing);

// 对齐
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^alignment)(NSTextAlignment alignment);

// 换行
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^lineBreakMode)(NSLineBreakMode mode);

// 段第一行头部缩进
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^firstLineHeadIndent)(CGFloat indent);

// 段头部缩进
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^headIndent)(CGFloat indent);

// 段尾部缩进
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^tailIndent)(CGFloat indent);

// 行高，iOS 的行高会在顶部增加空隙，效果一般不符合 UI 的认知，很少使用
// 这里为了完全匹配 Sketch 的行高效果，会根据当前字体对 baselineOffset 进行修正
// 具体见: https://joeshang.github.io/2018/03/29/ios-multiline-text-spacing/
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^lineHeight)(CGFloat lineHeight);

#pragma mark - Special

// 基线偏移
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^baselineOffset)(CGFloat offset);

// 连字
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^ligature)(CGFloat ligature);

// 字间距
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^kern)(CGFloat kern);

// 倾斜
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^obliqueness)(CGFloat obliqueness);

// 扩张
@property (nonatomic, copy, readonly) NSMutableAttributedString *(^expansion)(CGFloat expansion);

@end

@interface NSString (SCRAttributedStringBuilder)

// 生成 Attributed String
@property (nonatomic, copy, readonly) NSMutableAttributedString *attributedBuild;

@end
