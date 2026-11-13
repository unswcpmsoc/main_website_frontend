<script lang="ts">
    import CPMSOC_Logo from '$lib/assets/CPMSoc_Logo_With_Text_Baked.svg'
    import { NavigationMenu } from "bits-ui";
    import CaretDown from "phosphor-svelte/lib/CaretDown";
    import DiscordLogo from '$lib/assets/navigation/Discord_Logo.svg'
    import FacebookLogo from '$lib/assets/navigation/Facebook_Logo.svg'
    import InstagramLogo from '$lib/assets/navigation/Instagram_Logo.svg'

    import List from "phosphor-svelte/lib/List";
    import X from "phosphor-svelte/lib/X";
    import { slide } from "svelte/transition";

    import { clsx } from "clsx";
    import { twMerge } from "tailwind-merge";

    function cn(...inputs: (string | undefined | null | false)[]) {
        return twMerge(clsx(inputs));
    }

    const events: { title: string; href: string; description: string }[] = [
        {
            title: "Weekly Talks",
            href: "/talks",
            description:
                "Undergraduate mathematics weekly talks"
        },
        {
            title: "Upcoming Events",
            href: "/#upcoming-events",
            description:
                "CPMSoc's upcoming workshops, events and activities"
        },
        {
            title: "Past Workshops",
            href: "/workshops",
            description:
                "Past workshop resources"
        },
        {
            title: "Past Competitions",
            href: "/competitions",
            description:
                "Past competition outcomes and resources"
        },
    ];

    const about_us: { title: string; href: string; description: string }[] = [
        {
            title: "Contact",
            href: "/contact",
            description:
                "Contact us via email or connect on social media"
        },
        {
            title: "Constitution",
            href: "/constitution",
            description:
                "The official constitution of CPMSoc UNSW"
        },
        {
            title: "Grievances",
            href: "/grievances",
            description:
                "Our grievance resolution policy and form"
        },
        {
            title: "Sponsors",
            href: "/sponsors",
            description:
                "Sponsors of CPMSoc"
        },
    ];

    type ListItemProps = {
        className?: string;
        title: string;
        href: string;
        content: string;
    };

    let mobileMenuOpen = $state(false);
</script>

{#snippet ListItem({ className, title, content, href }: ListItemProps)}
    <li>
        <NavigationMenu.Link
                class={cn(
        "hover:bg-muted hover:text-accent-foreground focus:bg-muted focus:text-accent-foreground outline-hidden block select-none space-y-1 rounded-md p-3 leading-none no-underline transition-colors",
        className
      )}
                {href}
        >
            <div class="text-sm font-semibold leading-none">{title}</div>
            <p class="text-muted-foreground line-clamp-2 text-sm leading-snug">
                {content}
            </p>
        </NavigationMenu.Link>
    </li>
{/snippet}


<nav class="relative z-100 flex w-full items-center justify-between bg-[#f8f8f8] py-2 font-mono">
    <div class="flex flex-row items-center justify-center shrink-0">
        <a href="/" class="px-2 md:px-12">
            <img src={CPMSOC_Logo} alt="CPMSoc Logo for main header component" class="h-14" />
        </a>
    </div>

    <div class="hidden md:flex items-center pr-8">
        <NavigationMenu.Root class="relative z-10 flex justify-center">

            <NavigationMenu.List class="group flex list-none items-center justify-center p-1">
                <NavigationMenu.Item>
                    <NavigationMenu.Link
                            class="hover:text-accent-foreground focus:bg-muted focus:text-accent-foreground data-[state=open]:shadow-mini dark:hover:bg-muted dark:data-[state=open]:bg-muted focus:outline-hidden group inline-flex h-8 w-max items-center justify-center rounded-[7px] bg-transparent lg:px-4 px-3 py-2 text-sm font-medium transition-colors hover:bg-white disabled:pointer-events-none disabled:opacity-50 data-[state=open]:bg-white"
                            href="/"
                    >
                        <span class="hidden lg:inline font-semibold"> Home </span>
                        <span class="inline lg:hidden font-semibold"> Home </span>
                    </NavigationMenu.Link>
                </NavigationMenu.Item>

                <NavigationMenu.Item value="resources">
                    <NavigationMenu.Trigger
                            class="font-semibold hover:text-accent-foreground focus-visible:bg-muted focus-visible:text-accent-foreground data-[state=open]:shadow-mini dark:hover:bg-muted dark:data-[state=open]:bg-muted focus-visible:outline-hidden group inline-flex h-8 w-max items-center justify-center rounded-[7px] bg-transparent lg:px-4 px-3 py-2 text-sm transition-colors hover:bg-white disabled:pointer-events-none disabled:opacity-50 data-[state=open]:bg-white"
                    >
                        Resources
                        <CaretDown
                                class="relative top-[1px] ml-1 size-3 transition-transform duration-200 group-data-[state=open]:rotate-180"
                                aria-hidden="true"
                        />
                    </NavigationMenu.Trigger>
                    <NavigationMenu.Content
                            class="data-[motion=from-end]:animate-enter-from-right data-[motion=from-start]:animate-enter-from-left data-[motion=to-end]:animate-exit-to-right data-[motion=to-start]:animate-exit-to-left absolute left-0 top-0 sm:w-auto w-full"
                    >
                        <ul class="m-0 grid list-none gap-x-2.5 p-3 lg:w-[400px] w-[350px] lg:grid-flow-col lg:grid-rows-2 sm:p-[22px]">
                            <li class="row-span-2 mb-2 sm:mb-0">
                                <NavigationMenu.Link
                                        href="/blog"
                                        class="from-muted/50 to-muted bg-linear-to-b outline-hidden flex h-full w-full select-none flex-col justify-end rounded-md p-6 no-underline focus:shadow-md"
                                >
                                    <div class="mb-2 mt-4 text-lg font-semibold">Blog</div>
                                    <p class="text-muted-foreground text-sm leading-tight">
                                        Interesting mathematics and computing ideas
                                    </p>
                                </NavigationMenu.Link>
                            </li>
                            {@render ListItem({ href: "/cp101", title: "CP101", content: "Basics of competitive programming" })}
                            {@render ListItem({ href: "/cm101", title: "CM101", content: "Basics of competitive mathematics" })}
                        </ul>
                    </NavigationMenu.Content>
                </NavigationMenu.Item>

                <NavigationMenu.Item>
                    <NavigationMenu.Trigger
                            class="font-semibold hover:text-accent-foreground focus-visible:bg-muted focus-visible:text-accent-foreground data-[state=open]:shadow-mini dark:hover:bg-muted dark:data-[state=open]:bg-muted focus-visible:outline-hidden group inline-flex h-8 w-max items-center justify-center rounded-[7px] bg-transparent lg:px-4 px-3 py-2 text-sm transition-colors hover:bg-white disabled:pointer-events-none disabled:opacity-50 data-[state=open]:bg-white"
                    >
                        Events
                        <CaretDown
                                class="relative top-[1px] ml-1 size-3 transition-transform duration-200 group-data-[state=open]:rotate-180"
                                aria-hidden="true"
                        />
                    </NavigationMenu.Trigger>
                    <NavigationMenu.Content
                            class="data-[motion=from-end]:animate-enter-from-right data-[motion=from-start]:animate-enter-from-left data-[motion=to-end]:animate-exit-to-right data-[motion=to-start]:animate-exit-to-left absolute left-0 top-0 w-full sm:w-auto"
                    >
                        <ul class="grid gap-3 p-3 w-[400px] sm:p-6">
                            {#each events as component (component.title)}
                                {@render ListItem({ href: component.href, title: component.title, content: component.description })}
                            {/each}
                        </ul>
                    </NavigationMenu.Content>
                </NavigationMenu.Item>

                <NavigationMenu.Item>
                    <NavigationMenu.Trigger
                            class="font-semibold hover:text-accent-foreground focus-visible:bg-muted focus-visible:text-accent-foreground data-[state=open]:shadow-mini dark:hover:bg-muted dark:data-[state=open]:bg-muted focus-visible:outline-hidden group inline-flex h-8 w-max items-center justify-center rounded-[7px] bg-transparent lg:px-4 px-3 py-2 text-sm transition-colors hover:bg-white disabled:pointer-events-none disabled:opacity-50 data-[state=open]:bg-white"
                    >
                        About Us
                        <CaretDown
                                class="relative top-[1px] ml-1 size-3 transition-transform duration-200 group-data-[state=open]:rotate-180"
                                aria-hidden="true"
                        />
                    </NavigationMenu.Trigger>
                    <NavigationMenu.Content
                            class="data-[motion=from-end]:animate-enter-from-right data-[motion=from-start]:animate-enter-from-left data-[motion=to-end]:animate-exit-to-right data-[motion=to-start]:animate-exit-to-left absolute left-0 top-0 w-full sm:w-auto"
                    >
                        <ul class="grid gap-3 p-3 w-[400px] sm:p-6">
                            {#each about_us as component (component.title)}
                                {@render ListItem({ href: component.href, title: component.title, content: component.description })}
                            {/each}
                        </ul>
                    </NavigationMenu.Content>
                </NavigationMenu.Item>

                <NavigationMenu.Indicator
                        class="data-[state=hidden]:animate-fade-out data-[state=visible]:animate-fade-in top-full z-10 flex h-2.5 items-end justify-center overflow-hidden opacity-100 transition-[all,transform_250ms_ease] duration-200 data-[state=hidden]:opacity-0"
                >
                    <div class="bg-border relative top-[70%] size-2.5 rotate-[45deg] rounded-tl-[2px]"></div>
                </NavigationMenu.Indicator>
            </NavigationMenu.List>

            <div class="perspective-[2000px] absolute left-0 top-full flex w-full justify-center">
                <NavigationMenu.Viewport
                        class="text-popover-foreground bg-background data-[state=closed]:animate-scale-out data-[state=open]:animate-scale-in relative mt-2.5 h-[var(--bits-navigation-menu-viewport-height)] w-full origin-[top_center] overflow-hidden rounded-md border shadow-lg transition-[width,_height] duration-200 sm:w-[var(--bits-navigation-menu-viewport-width)] "
                />
            </div>
        </NavigationMenu.Root>

        <div class="flex flex-row items-center justify-center gap-3 border-l border-gray-300 pl-6 shrink-0">
            <a
                    href="https://discord.com/invite/9uxgxHY3pP"
                    target="_blank"
                    rel="noreferrer noopener"
                    class="transition-opacity hover:opacity-70"
            >
                <img src={DiscordLogo} alt="Discord" class="size-6" />
            </a>

            <a
                    href="https://www.facebook.com/CPMSoc/"
                    target="_blank"
                    rel="noreferrer noopener"
                    class="transition-opacity hover:opacity-70"
            >
                <img src={FacebookLogo} alt="Facebook" class="size-6" />
            </a>

            <a
                    href="https://www.instagram.com/cpmsoc_unsw/?hl=en"
                    target="_blank"
                    rel="noreferrer noopener"
                    class="transition-opacity hover:opacity-70"
            >
                <img src={InstagramLogo} alt="Instagram" class="size-6" />
            </a>
        </div>
    </div>

    <div class="md:hidden flex items-center pr-4">
        <button
                onclick={() => mobileMenuOpen = !mobileMenuOpen}
                class="p-2 text-foreground focus:outline-none"
                aria-label="Toggle Menu"
        >
            {#if mobileMenuOpen}
                <X size={28} class="hover:cursor-pointer"/>
            {:else}
                <List size={28} class="hover:cursor-pointer"/>
            {/if}
        </button>
    </div>

<!--    This is for mobile screens with the navigation when the screen is too small -->
    {#if mobileMenuOpen}
        <div
                transition:slide={{ duration: 200 }}
                class="absolute top-full left-0 w-full bg-[#f8f8f8] border-b border-gray-200 shadow-xl flex flex-col p-6 gap-2 md:hidden z-40 max-h-[85vh] overflow-y-auto"
        >
            <a href="/" class="text-base font-semibold py-2 hover:text-accent-foreground" onclick={() => mobileMenuOpen = false}>
                Home
            </a>

            <details class="group">
                <summary class="flex justify-between items-center text-base font-semibold py-2 cursor-pointer list-none text-foreground outline-none">
                    Resources
                    <CaretDown class="transition-transform duration-200 group-open:rotate-180" size={16}/>
                </summary>
                <div class="pl-4 flex flex-col gap-2 mt-1 border-l-2 border-gray-200 ml-1">
                    <a href="/blog" class="py-1 text-sm text-muted-foreground hover:text-foreground" onclick={() => mobileMenuOpen = false}>Blog</a>
                    <a href="/cp101" class="py-1 text-sm text-muted-foreground hover:text-foreground" onclick={() => mobileMenuOpen = false}>CP101</a>
                    <a href="/cm101" class="py-1 text-sm text-muted-foreground hover:text-foreground" onclick={() => mobileMenuOpen = false}>CM101</a>
                </div>
            </details>

            <details class="group">
                <summary class="flex justify-between items-center text-base font-semibold py-2 cursor-pointer list-none text-foreground outline-none">
                    Events
                    <CaretDown class="transition-transform duration-200 group-open:rotate-180" size={16}/>
                </summary>
                <div class="pl-4 flex flex-col gap-2 mt-1 border-l-2 border-gray-200 ml-1">
                    {#each events as item}
                        <a href={item.href} class="py-1 text-sm text-muted-foreground hover:text-foreground" onclick={() => mobileMenuOpen = false}>{item.title}</a>
                    {/each}
                </div>
            </details>

            <details class="group">
                <summary class="flex justify-between items-center text-base font-semibold py-2 cursor-pointer list-none text-foreground outline-none">
                    About Us
                    <CaretDown class="transition-transform duration-200 group-open:rotate-180" size={16}/>
                </summary>
                <div class="pl-4 flex flex-col gap-2 mt-1 border-l-2 border-gray-200 ml-1">
                    {#each about_us as item}
                        <a href={item.href} class="py-1 text-sm text-muted-foreground hover:text-foreground" onclick={() => mobileMenuOpen = false}>{item.title}</a>
                    {/each}
                </div>
            </details>

            <div class="flex flex-row items-center gap-6 mt-6 pt-6 border-t border-gray-200">
                <a href="https://discord.com/invite/9uxgxHY3pP" target="_blank" rel="noreferrer noopener" class="transition-opacity hover:opacity-70">
                    <img src={DiscordLogo} alt="Discord" class="size-8" />
                </a>
                <a href="https://www.facebook.com/CPMSoc/" target="_blank" rel="noreferrer noopener" class="transition-opacity hover:opacity-70">
                    <img src={FacebookLogo} alt="Facebook" class="size-8" />
                </a>
                <a href="https://www.instagram.com/cpmsoc_unsw/?hl=en" target="_blank" rel="noreferrer noopener" class="transition-opacity hover:opacity-70">
                    <img src={InstagramLogo} alt="Instagram" class="size-8" />
                </a>
            </div>
        </div>
    {/if}
</nav>