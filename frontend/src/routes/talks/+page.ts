import type { PageLoad } from './$types';
import { Marked } from 'marked';
import talksMarkdown from './talks.md?raw';

export const prerender = true;

function renderMarkdown(markdown: string): string {
    const localMarkedInstance = new Marked();

    const renderer = {
        heading(this: any, token: any): string {
            const text = this.parser ? this.parser.parseInline(token.tokens) : token.text;
            const classes: Record<number, string> = {
                1: 'text-3xl md:text-4xl font-bold text-[#5b8ddb] tracking-tight mt-2',
                2: 'text-2xl md:text-[28px] font-bold text-[#141414] tracking-tight mt-8 mb-1',
                3: 'text-xl font-bold text-[#141414] tracking-tight mt-6 mb-1'
            };
            return `<h${token.depth} class="${classes[token.depth] ?? classes[3]}">${text}</h${token.depth}>`;
        },

        link(this: any, token: any): string {
            const href = token.href as string;
            const text = this.parser ? this.parser.parseInline(token.tokens) : token.text;
            const external = /^https?:\/\//.test(href);
            const target = external ? ' target="_blank" rel="noreferrer noopener"' : '';
            return `<a href="${href}"${target} class="text-[#7862e2] underline decoration-[#7862e2]/30 underline-offset-2 hover:decoration-[#7862e2]">${text}</a>`;
        },

        paragraph(this: any, token: any): string {
            const text = this.parser ? this.parser.parseInline(token.tokens) : token.text;
            return `<p class="text-lg leading-relaxed text-[#2b2b2b] mb-4">${text}</p>`;
        },

        list(this: any, token: any): string {
            const tag = token.ordered ? 'ol' : 'ul';
            const marker = token.ordered ? 'list-decimal' : 'list-disc';
            let body = '';
            for (const item of token.items) {
                const text = this.parser ? this.parser.parseInline(item.tokens) : item.text;
                body += `<li class="mb-2 pl-1">${text}</li>`;
            }
            return `<${tag} class="${marker} list-outside pl-6 mb-4 text-lg leading-relaxed text-[#2b2b2b] space-y-1">${body}</${tag}>`;
        }
    };

    localMarkedInstance.use({ renderer: renderer as any });
    return localMarkedInstance.parse(markdown) as string;
}

export const load: PageLoad = () => {
    return { html: renderMarkdown(talksMarkdown) };
};
