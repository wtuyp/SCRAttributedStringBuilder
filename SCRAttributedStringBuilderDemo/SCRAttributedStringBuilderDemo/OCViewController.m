//
//  ViewController.m
//  SCRAttributedStringBuilderDemo
//
//  Created by Chuanren Shang on 2018/4/21.
//  Copyright © 2018 Chuanren Shang. All rights reserved.
//

#import "OCViewController.h"
#import "NSMutableAttributedString+SCRAttributedStringBuilder.h"

@interface OCViewController ()

@end

@implementation OCViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSShadow *shadow = [[NSShadow alloc] init];
    shadow.shadowColor = [UIColor blueColor];
    shadow.shadowOffset = CGSizeMake(2, 2);
    NSTextAttachment *attachment = [[NSTextAttachment alloc] init];
    attachment.image = [UIImage imageNamed:@"luffer"];
    attachment.bounds = CGRectMake(0, 0, 50, 50);
    NSString *text = @"测试多行文字测试多行文字测试多行文字链接测试多行文字测试多行文字链接测试多行文字测试多行文字测试多行文字链接测试多行文字测试多行文字测试多行文字\n";
    self.label.attributedText = @"颜色字体\n".attributedBuild.fontSize(30).color([UIColor purpleColor])
        .range(1, 1).color([UIColor redColor])
        .insert(@"/插入文字/", 2).fontSize(20).color([UIColor blueColor])
        .append(text).firstLineHeadIndent(20).lineHeight(25).paragraphSpacing(20)
        .match(@"链接").hexColor(0xFF4400).backgroundColor([UIColor lightGrayColor])
        .matchFirst(@"链接").underlineStyle(NSUnderlineStyleThick).underlineColor([UIColor greenColor])
        .matchLast(@"链接").strikethroughStyle(NSUnderlineStyleSingle).strikethroughColor([UIColor yellowColor])
        .append(text).alignment(NSTextAlignmentCenter).headIndent(20).tailIndent(-20).lineSpacing(10)
        .append(@"路飞").font([UIFont systemFontOfSize:25]).strokeWidth(2).strokeColor([UIColor darkGrayColor])
        .headInsertImage([UIImage imageNamed:@"luffer"], CGSizeMake(50, 50), [UIFont systemFontOfSize:25])
        .appendSizeImage([UIImage imageNamed:@"luffer"], CGSizeMake(50, 50))
        .appendCustomImage([UIImage imageNamed:@"luffer"], CGSizeMake(50, 50), [UIFont systemFontOfSize:15])
        .append(@"路飞").font([UIFont systemFontOfSize:15])
        .appendSpacing(20)
        .appendAttachment(attachment)
        .insertImage([UIImage imageNamed:@"luffer"], CGSizeMake(50, 50), 0, [UIFont systemFontOfSize:30])
        .append(@"\n阴影").shadow(shadow).append(@"基线偏移\n").baselineOffset(-5)
        .append(@" ").backgroundColor([UIColor redColor]).fontSize(2);
}

@end
